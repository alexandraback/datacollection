# Written for Python 2.7.9

from optparse import OptionParser
from StringIO import StringIO
import sys

# Expected format of TEST_CASES is a list of tuples of (input, expected_output)
TEST_CASES = [("""7
2 1
ik
3 1
ijk
3 1
kji
2 6
ji
1 10000
i
2 10
ji
3 5
ijk
""","""Case #1: NO
Case #2: YES
Case #3: NO
Case #4: YES
Case #5: NO
Case #6: YES
Case #7: YES
""")]


mapping = {
    ('', 'i'): (1, 'i'),
    ('', 'j'): (1, 'j'),
    ('', 'k'): (1, 'k'),
    ('i', 'i'): (-1, ''),
    ('i', 'j'): (1, 'k'),
    ('i', 'k'): (-1, 'j'),
    ('j', 'i'): (-1, 'k'),
    ('j', 'j'): (-1, ''),
    ('j', 'k'): (1, 'i'),
    ('k', 'i'): (1, 'j'),
    ('k', 'j'): (-1, 'i'),
    ('k', 'k'): (-1, ''),
}


def parse_input(input_reader):
    case_count = int(input_reader.readline())
    case_idx = 0
    while case_count > case_idx:
        case_idx += 1
        input_values = {"case": case_idx,}
        L, X = input_reader.readline().strip().split()
        input_values['L'] = int(L)
        input_values['X'] = int(X)
        input_values['chars'] = input_reader.readline().strip()
        yield input_values


def solve_problem(output_writer=sys.stdout, **kwargs):
    case = kwargs['case']
    L = kwargs['L']
    X = kwargs['X']
    chars = kwargs['chars']
    if len(set(chars)) < 2:
        total = 0
    else:
        total = L * X
    pointer = 0
    count = 0
    answer = "YES"
    loops_left = X
    for target in ['i', 'j', 'k']:
        pointer_start = pointer
        sign = 1
        letter = ''
        loops_used = 0
        while count < total:
            next_sign, letter = mapping[(letter, chars[pointer])]
            sign *= next_sign
            count += 1
            pointer += 1
            if pointer == L:
                pointer = 0
                loops_left -= 1
            if pointer == pointer_start:
                # If this matches then we've done a full loop of the characters
                # this isn't the same as moving back to the start as we may not
                # have begun at the first character.
                loops_used += 1
            if (sign == 1 and letter == target) or loops_used == 4:
                # Stop either when we've found the letter we want, or gone
                # round four times (which means we've effectively multiplied by
                # 1 and so will never find what we're looking for).
                break
        if sign != 1 or letter != target:
            # If we exited the while loop without finding our target then this
            # case is a fail and we shouldn't process any more.
            answer = "NO"
            count = total
            pointer = L
    # At this point we've either identified a fail or we've found the letters
    # in the correct order and need to check the rest of the string multiplies
    # out to be 1.
    # Start by finding where we get to at the end of the current string loop
    # if there's anything remaining.
    letter = ''
    sign = 1
    if pointer > 0:
        while pointer < L:
            next_sign, letter = mapping[(letter, chars[pointer])]
            sign *= next_sign
            pointer += 1
            if pointer == L:
                loops_left -= 1
    # Mod the remaining loops by 4 since x^4 will always be 1 whatever x is
    # thus we only care about the number when it's not a multiple of 4
    loops_left %= 4
    # And then multiply through those loops.
    for character in (chars * loops_left):
        next_sign, letter = mapping[(letter, character)]
        sign *= next_sign
    if sign != 1 or letter != '':
        answer = "NO"
    print >>output_writer, "Case #%d: %s" % (case, answer)

def solve_inputs(input_reader, output_writer):
    """
    Loop through each problem input in input reader and solve it.

    Outputs responses to output_writer.
    """
    for input_values in parse_input(input_reader):
        solve_problem(output_writer=output_writer, **input_values)

def run_tests():
    idx = 0
    all_pass = True
    for problem_input, expected_output in TEST_CASES:
        idx += 1
        input_reader = StringIO(problem_input)
        output_writer = StringIO()
        solve_inputs(input_reader, output_writer)
        problem_output = output_writer.getvalue()
        if problem_output == expected_output:
            print "Test %d: Success" % idx
        else:
            all_pass = False
            print "Test %d: Failure" % idx
        input_reader.close()
        output_writer.close()
    if all_pass:
        print "All tests were successful!"
    else:
        print "Something didn't match - try again."

def main():
    parser = OptionParser()
    parser.add_option("-f", "--file",
                      dest="filename_stem",
                      help="read input from FILE.in and write to FILE.out",
                      metavar="FILE")

    (options, args) = parser.parse_args()
    if options.filename_stem:
        print "Running in file mode."
        input_reader = open("%s.in" % options.filename_stem, "r")
        output_writer = open("%s.out" % options.filename_stem, "w")
        solve_inputs(input_reader, output_writer)
    else:
        print "Running in test mode."
        run_tests()

if __name__ == "__main__":
    main()
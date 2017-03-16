# Written for Python 2.7.9

from collections import defaultdict
from optparse import OptionParser
from StringIO import StringIO
import sys

# Expected format of TEST_CASES is a list of tuples of (input, expected_output)
TEST_CASES = [("""5
7 6 6
BANANAS
MONKEY
2 3 4
AA
AAA
2 1 2
AB
B
6 2 2
GOOGLE
GO
26 11 100
ABCDEFGHIJKLMNOPQRSTUVWXYZ
ROSENCRANTZ
""","""Case #1: 0.0000000
Case #2: 0.0000000
Case #3: 1.0000000
Case #4: 0.8888889
Case #5: 9.0000000
""")]

def parse_input(input_reader):
    case_count = int(input_reader.readline())
    case_idx = 0
    while case_count > case_idx:
        case_idx += 1
        input_values = {"case": case_idx,}
        parts = input_reader.readline().strip().split()
        input_values['keys'] = int(parts[0])
        input_values['target_length'] = int(parts[1])
        input_values['typed'] = int(parts[2])
        input_values['keyboard'] = input_reader.readline().strip()
        assert len(input_values['keyboard']) == input_values['keys']
        input_values['target'] = input_reader.readline().strip()
        assert len(input_values['target']) == input_values['target_length']
        yield input_values


def solve_problem(
    typed, keys, target_length, keyboard, target, output_writer=sys.stdout,
    **kwargs
):
    case = kwargs['case']
    # Only one possible output so the number of bananas left will always be 0
    if keys == 1:
        print_answer(output_writer, case, 0)
        return
    frequencies = defaultdict(lambda: 0)
    for key in keyboard:
        frequencies[key] += 1
    overlap_point = 0
    overlap_index = 0
    # Quick search for insufficient keyboards.
    probability_numerator = 1.0
    probability_denominator = 1.0
    for letter in target:
        if letter not in frequencies:
            # Bail early if the key isn't on the keyboard
            print_answer(output_writer, case, 0)
            return
        else:
            probability_numerator *= frequencies[letter]
            probability_denominator *= keys
    overlap_points = []
    overlap_index = 1
    substring = target[:-1]
    while substring:
        if target.endswith(substring):
            overlap_points.append(overlap_index)
        overlap_index += 1
        substring = substring[:-1]
    overlap_points.append(overlap_index)
    max_occurrences = 1 + ((typed - target_length) / overlap_points[0])
    number_start_points = 1 + typed - target_length
    predicted_awarded = (probability_numerator * max_occurrences) / probability_denominator

    answer = max_occurrences - predicted_awarded
    print_answer(output_writer, case, answer)

def print_answer(output_writer, case, answer):
    print >>output_writer, "Case #%d: %.7f" % (case, answer)

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
            print problem_output
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
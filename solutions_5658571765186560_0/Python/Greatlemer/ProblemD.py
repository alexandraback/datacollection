# Written for Python 2.7.9

from optparse import OptionParser
from StringIO import StringIO
import sys

# Expected format of TEST_CASES is a list of tuples of (input, expected_output)
TEST_CASES = [("""5
2 2 2
2 1 3
4 4 1
3 2 3
4 4 3
""","""Case #1: GABRIEL
Case #2: RICHARD
Case #3: RICHARD
Case #4: GABRIEL
Case #5: GABRIEL
""")]

def parse_input(input_reader):
    case_count = int(input_reader.readline())
    case_idx = 0
    while case_count > case_idx:
        case_idx += 1
        # Implementation of parsing code goes here.
        input_values = {"case": case_idx,}
        x, r, c = input_reader.readline().strip().split()
        input_values['X'] = int(x)
        input_values['R'] = int(r)
        input_values['C'] = int(c)
        yield input_values


def solve_problem(output_writer=sys.stdout, **kwargs):
    case = kwargs['case']
    X = kwargs['X']
    C = kwargs['C']
    R = kwargs['R']
    winner = "???"
    if C > R:
        R, C = C, R
    if X > 6:
        # Can always choose a block with a single square hole inside
        winner = "RICHARD"
    elif (R * C) % X != 0:
        # Never be possible for blocks to fit
        winner = "RICHARD"
    elif R < X and C < X:
        # Pick the X * 1 block which can't fit
        winner = "RICHARD"
    elif ((X + 1) / 2) > C:
        # Pick an L shape that's too big for the grid.
        winner = "RICHARD"
    elif X < 4:
        # Can't pick impossible shapes for X < 4 once other criteria pass
        winner = "GABRIEL"
    elif (X == 4 and C == 2) or (X == 6 and R == 6 and C == 3):
        # Other two cases where a T or an L piece can make it impossible
        winner = "RICHARD"
    else:
        # Everything else should be possible
        winner = "GABRIEL"

    answer = "{0}".format(winner)
    # Implementation of code to solve the problem goes here.
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
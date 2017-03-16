# Written for Python 2.7.9

from optparse import OptionParser
from StringIO import StringIO
import sys

# Expected format of TEST_CASES is a list of tuples of (input, expected_output)
TEST_CASES = [("""3
1
19
23
""","""Case #1: 1
Case #2: 19
Case #3: 15
""")]

def parse_input(input_reader):
    case_count = int(input_reader.readline())
    case_idx = 0
    while case_count > case_idx:
        case_idx += 1
        input_values = {"case": case_idx,}
        input_values['target'] = int(input_reader.readline().strip())
        yield input_values


def solve_problem(output_writer=sys.stdout, **kwargs):
    case = kwargs['case']
    target = kwargs['target']
    answer = 0
    while(target > 0):
        if target < 21:
            answer += target
            break
        target_str = str(target)
        if target_str[-1] == "0":
            answer += 1
            target -= 1
            continue
        start_point = 0
        end_point = len(target_str) - 1
        while start_point < end_point:
            start = int(target_str[start_point])
            end = int(target_str[end_point])
            if start > end:
                target_str = target_str[::-1]
                target = int(target_str)
                answer += 1
                break
            elif end > start:
                diff = end - start
                diff *= (10**start_point)
                answer += diff
                target -= diff
                break
            start_point += 1
            end_point -= 1
        if start_point >= end_point:
            target -= 1
            answer += 1
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
from optparse import OptionParser

COOKIE_RATE = 2


def should_continue(time_till_end, time_with_farm):
    return time_till_end - time_with_farm > 1E-6


def solve_case(input_file):
    (c, f, x) = [float(i) for i in input_file.readline().split()]
    cookie_rate = COOKIE_RATE
    time = 0
    time_till_end = x / cookie_rate
    time_till_farm = c / cookie_rate
    time_with_farm = time_till_farm + x / (cookie_rate + f)
    best_time = min(time_till_end, time_with_farm)
    while should_continue(best_time, time):
        cookie_rate += f
        time = time_till_farm
        time_till_end = time_with_farm
        time_till_farm = time + c / cookie_rate
        time_with_farm = time_till_farm + x / (cookie_rate + f)
        best_time = min(best_time, time_till_end, time_with_farm)
    return round(best_time, 7)


def process_files(input_file, output_file):
    number_of_cases = int(input_file.readline())
    for case in range(number_of_cases):
        result = solve_case(input_file)
        output_file.write('Case #%i: %s\n' % (case + 1, result))


if __name__ == '__main__':
    parser = OptionParser()
    parser.add_option('-i', '--input', dest='inputFile',
                      help='test case file', metavar='FILE')
    parser.add_option('-o', '--output', dest='outputFile',
                      help='result file', metavar='FILE')
    (options, args) = parser.parse_args()

    if not options.inputFile or not options.outputFile:
        parser.error("options -i and -o are not optional")
    else:
        process_files(open(options.inputFile, 'r'), open(options.outputFile, 'w'))


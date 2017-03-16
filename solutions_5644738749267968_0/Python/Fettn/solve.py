from optparse import OptionParser
import math


def output_line(field, none_mines, c):
    line_result = []
    for column in range(c):
        line_result.append('.' if column < none_mines else '*')
    field.append(line_result)


def search_d_stone(naomi_stone, ken_stones):
    old_stone = None
    for ken_stone in ken_stones:
        if naomi_stone > ken_stone:
            old_stone = ken_stone
    if old_stone:
        return old_stone
    else:
        return ken_stones[-1]


def play_d_war(naomi_stones, ken_stones):
    naomi_stones.sort()
    ken_stones.sort()
    score = 0
    for naomi_stone in naomi_stones:
        ken_stone = search_d_stone(naomi_stone, ken_stones)
        ken_stones.remove(ken_stone)
        if naomi_stone > ken_stone:
            score += 1
    return score


def search_n_stone(ken_stones, naomi_stone):
    for ken_stone in ken_stones:
        if ken_stone > naomi_stone:
            return ken_stone
    return ken_stones[0]


def play_n_war(naomi_stones, ken_stones):
    naomi_stones.sort()
    ken_stones.sort()
    score = 0
    for naomi_stone in naomi_stones:
        ken_stone = search_n_stone(ken_stones, naomi_stone)
        ken_stones.remove(ken_stone)
        if naomi_stone > ken_stone:
            score += 1
    return score


def solve_case(input_file):
    number_of_stones = int(input_file.readline())
    naomi_stones = [float(x) for x in input_file.readline().split()]
    ken_stones = [float(x) for x in input_file.readline().split()]

    deceitful = play_d_war(naomi_stones[:], ken_stones[:])
    normal = play_n_war(naomi_stones, ken_stones)
    return "%i %i" % (deceitful, normal)


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
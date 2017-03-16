def run_case(input):
    score_1, score_2 = read_strs(input)
    best = get_best(score_1, score_2)
    return "{} {}".format(best[1], best[2])


def get_best(score_1, score_2):
    for pos in range(len(score_1)):
        if score_1[pos] == score_2[pos] == "?":
            return min([
                get_best(score_1.replace('?', surround, 1), score_2)
                for surround in get_surrounding_numbers(0)])
        elif score_1[pos] == "?":
            return min([
                get_best(score_1.replace('?', surround, 1), score_2)
                for surround in get_surrounding_numbers(score_2[pos])])
        elif score_2[pos] == "?":
            return min([
                get_best(score_1, score_2.replace('?', surround, 1))
                for surround in get_surrounding_numbers(score_1[pos])])

    return (abs(int(score_1) - int(score_2)), score_1, score_2)


def get_surrounding_numbers(num):
    num = int(num)
    nums = {(num - 1) % 10, num % 10, (num + 1) % 10}
    nums.add(0)
    nums.add(9)
    return [str(x) for x in nums]


def replace_at_index(st, replace_with, replace_at):
    return st[:replace_at] + replace_with + st[replace_at + 1:]

##############################
#    CODE JAM BOILERPLATE    #
##############################


def read_ints(input, n=1):
    """ Read n integers from input - all on one line, space separated """
    return (int(st) for st in read_strs(input, n))


def read_strs(input, n=1):
    """ Read n strings from input - all on one line, space separated """
    return input.pop(0).rstrip("\n").split(" ")

# GCJ boiler plate...call run_case for each case given
if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(10000)
    lines = sys.stdin.readlines()
    sys.stdin = open('/dev/tty')
    num_cases = int(lines.pop(0))
    for case_num in range(num_cases):
        print("Case #%d: %s" % (case_num + 1, run_case(lines)))

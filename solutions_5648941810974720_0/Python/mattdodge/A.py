nums = [
    (0, "ZERO"),
    (8, "EIGHT"),
    (2, "TWO"),
    (6, "SIX"),
    (3, "THREE"),
    (4, "FOUR"),
    (1, "ONE"),
    (5, "FIVE"),
    (7, "SEVEN"),
    (9, "NINE")]


def run_case(input):
    my_str, = read_strs(input)
    out_str = ""
    for num_digit, num_str in nums:
        times, my_str = remove_str(num_str, my_str)
        out_str += str(num_digit) * times

    assert len(my_str) == 0
    return ''.join(sorted(out_str))


def remove_str(to_remove, remove_from, already_removed=0):
    """ Remove the letters - return (num times removed, new str) """
    tmp_str = remove_from
    for c in to_remove:
        tmp_str = tmp_str.replace(c, '', 1)

    if len(tmp_str) + len(to_remove) == len(remove_from):
        # we successfully removed it
        return remove_str(to_remove, tmp_str, already_removed + 1)
    else:
        # couldn't remove
        return (already_removed, remove_from)

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

import math
import itertools

def is_polyndrom(x):
    if x < 10:
        return True
    s = str(x)
    n = len(s)/2
    return s[:n] == "".join(reversed(s[-n:]))

def enumerate_fair_and_square_candidate(digits_len):
    if digits_len < 1:
        return

    if digits_len == 1:
        yield 0
        yield 1
        yield 2
        yield 3
        return

    if digits_len % 2 == 0:
        mid_values = [""]
        # 2000...0002
        yield int("".join(["2"] + (["0"] * (digits_len - 2)) + ["2"]))
    else:
        mid_values = ["0", "1", "2"]
        # 2xxx0xxx2 and 2xxx1xxx2 patterns
        yield int("".join(["2"] + (["0"] * (digits_len/2 - 1)) + ["0"] + (["0"] * (digits_len/2 - 1)) + ["2"]))
        yield int("".join(["2"] + (["0"] * (digits_len/2 - 1)) + ["1"] + (["0"] * (digits_len/2 - 1)) + ["2"]))

    # it seems that candadates are polyndroms with digits 0, 1 and 2 in the middle
    for e in itertools.product("01", repeat = digits_len/2):
        if e[0] != "0":
            for mid_val in mid_values:
                yield int("".join(e)+mid_val+"".join(reversed(e)))

def enumerate_fair_and_square_candidates(start, end):
    #return xrange(start, end+1)
    digits_min_len = len(str(start))
    digits_max_len = len(str(end))
    for digits_len in range(digits_min_len, digits_max_len+1):
        for candidate in enumerate_fair_and_square_candidate(digits_len):
            if candidate >= start and candidate <= end:
                yield candidate

def count_fair_and_square_numbers(start, end):
    sqrt_start = int(math.ceil(math.sqrt(start)))
    sqrt_end = int(math.floor(math.sqrt(end)))
    count = 0
    for x in (enumerate_fair_and_square_candidates(sqrt_start, sqrt_end)):
        if is_polyndrom(x) and is_polyndrom(x*x):
            count += 1
            #print x, x*x
    return count

def main():
    num_of_cases = int(raw_input())
    for i in range(num_of_cases):
        range_start, range_end = [int(e) for e in raw_input().split()][:2]
        print "Case #%d: %d" % (i+1, count_fair_and_square_numbers(range_start, range_end))
if __name__ == '__main__':
    pass
    main()

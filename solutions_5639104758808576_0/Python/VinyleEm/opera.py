def min_extras(audience):
    ret, total = 0, 0
    for i, c in enumerate(audience):
        add = i - total if c > 0 and total < i else 0
        ret += add
        total = total + c + add

    return ret


def main():
    num_cases = int(raw_input())
    for cas in xrange(num_cases):
        _, audience = raw_input().split()
        print "Case #%d: %d" % (cas + 1, min_extras(map(int, audience)))


if __name__ == '__main__':
    main()

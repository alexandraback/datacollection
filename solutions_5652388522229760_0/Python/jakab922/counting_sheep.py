def to_digits(num):
    ret = []
    while num > 0:
        ret.append(num % 10)
        num /= 10
    return ret


if __name__ == "__main__":
    T = int(raw_input().strip())
    for i in xrange(T):
        base_num = int(raw_input().strip())
        if base_num == 0:
            print "Case #%s: INSOMNIA" % (i + 1,) 
            continue
        was = set(to_digits(base_num))
        curr_num = base_num
        while len(was) < 10:
            curr_num += base_num
            for el in to_digits(curr_num):
                was.add(el)
        print "Case #%s: %s" % (i + 1, curr_num)

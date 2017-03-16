def read_n_int(n):
    ints = [int(s) for s in input().split(" ")]
    if len(ints) != n:
        raise ValueError('Expected %i ints, got %i' % (n, len(ints)))
    if n == 1:
        return ints[0]
    return ints


t = read_n_int(1)
for i in range(1, t + 1):
    n = input()
    w = []

    for letter in n:
        if len(w) == 0:
            w.append(letter)
        else:
            if letter >= w[0]:
                w.insert(0, letter)
            else:
                w.append(letter)

    print("Case #%i: %s" % (i, ''.join(w)))

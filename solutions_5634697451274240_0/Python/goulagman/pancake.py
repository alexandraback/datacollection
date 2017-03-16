def read_n_int(n):
    ints = [int(s) for s in input().split(" ")]
    if len(ints) != n:
        raise ValueError('Expected %i ints, got %i' % (n, len(ints)))
    if n == 1:
        return ints[0]
    return ints


def inv(n):
    # Turn 0 into 1 and vice versa
    return (1 - n)


t = read_n_int(1)
for i in range(1, t + 1):
    seq = input()

    # Tranlate into a list of 1 and Os
    seq = [1 if s == '+' else 0 for s in seq]

    n = 0
    while 0 in seq:
        if 1 not in seq:
            # All flipped, one flip is needed
            n += 1
            break

        # Find the first difference
        ref = seq[0]
        ind = seq.index(inv(ref))

        # Flip pancakes above the difference
        seq[:ind] = [inv(j) for j in reversed(seq[:ind])]

        n += 1

    print("Case #{}: {}".format(i, n))

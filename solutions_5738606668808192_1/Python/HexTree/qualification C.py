import itertools

N = 32
J = 500

#
# def isprime(n):
#     if n == 2:
#         return -1
#
#     if not n & 1:
#         return 2
#
#     for x in range(3, int(n**0.5) + 1, 2):
#         if n % x == 0:
#             return x
#
#     return -1

def unique_permutations(seq):
    """
    Yield only unique permutations of seq in an efficient way.

    A python implementation of Knuth's "Algorithm L", also known from the
    std::next_permutation function of C++, and as the permutation algorithm
    of Narayana Pandita.
    """

    # Precalculate the indices we'll be iterating over for speed
    i_indices = range(len(seq) - 1, -1, -1)
    k_indices = i_indices[1:]

    # The algorithm specifies to start with a sorted version
    seq = sorted(seq)

    while True:
        yield seq

        # Working backwards from the last-but-one index,           k
        # we find the index of the first decrease in value.  0 0 1 0 1 1 1 0
        for k in k_indices:
            if seq[k] < seq[k + 1]:
                break
        else:
            # Introducing the slightly unknown python for-else syntax:
            # else is executed only if the break statement was never reached.
            # If this is the case, seq is weakly decreasing, and we're done.
            return

        # Get item from sequence only once, for speed
        k_val = seq[k]

        # Working backwards starting with the last item,           k     i
        # find the first one greater than the one at k       0 0 1 0 1 1 1 0
        for i in i_indices:
            if k_val < seq[i]:
                break

        # Swap them in the most efficient way
        (seq[k], seq[i]) = (seq[i], seq[k])                #       k     i
                                                           # 0 0 1 1 1 1 0 0

        # Reverse the part after but not                           k
        # including k, also efficiently.                     0 0 1 1 0 0 1 1
        seq[k + 1:] = seq[-1:k:-1]


with open("data1.txt", 'w') as g:
    counter = 0
    g.write("Case #1: \n")

    digits = [1]*2 + [0]*(((N-2)/2) - 2)
    for i in unique_permutations(digits):
        for j in unique_permutations(digits):
            jamcoin = [r for s in zip(i, j) for r in s]
            jamcoin.append(1)
            jamcoin.insert(0, 1)

            divisors = [3, 2, 3, 2, 7, 2, 3, 2, 3]

            for base in range(2, 11):
                jamcoin.reverse()
                num = 0
                for k in range(32):
                    num += jamcoin[k]*(base**k)
                jamcoin.reverse()
                if num % divisors[base-2] != 0:
                    print "ERROR", jamcoin, num, base, divisors[base-2]

            strjam = "".join([str(x) for x in jamcoin]) + " "
            output = strjam + " ".join([str(x) for x in divisors])
            g.write(output + "\n")

            counter += 1
            if counter == J:
                break

        if counter == J:
            break
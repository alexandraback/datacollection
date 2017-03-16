import math

CHAR_DIVISORS = [3, 2, 5, 2, 7, 2, 9, 2, 11]

COMPONENTS = ["0000", "0011", "1100", "1001", "1111", "0110"]


def validate_jamcoin(jamcoin, divisors):
    for base in range(2, 11):
        number = int(jamcoin, base)
        if number % divisors[base-2] != 0 or \
           number == divisors[base-2] or number == 1:
            return False
    return True


def generate_jamcoins_and_proofs(N, J):
    # below we assume that N = 32 or N = 16
    # although it is not used explicitly in computations,
    # for other combinations of (N,J) the following method
    # may fail -- it is straightforward to calculate that
    # it wll work for numbers given in problem statement

    # calculate how many times we have to combine different groups
    # from COMPONENTS to obtain at least J different numbers
    # this is the smallest natural number k such that 6 ** k >= j
    # so -- calculate log_6(J) and take its ceiling
    groups_no = math.ceil(math.log(J, 6))

    # now check if we indeed can put those many groups between 1 and 1
    # in our jamcoin of length N
    if (N-2) // 4 < groups_no:
        # if no - then this method won't work (it can be tweaked
        # a bit, but it's not neccessary for this problem)
        raise ValueError("This method won't work for given (N,J).")

    middles = [""]
    for k in range(groups_no):
        middles = [middle + component for component in COMPONENTS
                   for middle in middles]

    # now add padding - we may fill it with zeros
    padding_len = N - len(middles[0]) - 2
    padding = padding_len * "0"

    jamcoins = ["1" + middle + padding + "1" for middle in middles[0:J]]


    # perform validations, just to not send incorrect output

    if len(jamcoins) != J:
        raise RuntimeError("Something went wrong...")
    for jamcoin in jamcoins:
        if not validate_jamcoin(jamcoin, CHAR_DIVISORS) or len(jamcoin) != N:
            raise RuntimeError("Something went wrong...")

    return [(jamcoin, CHAR_DIVISORS) for jamcoin in jamcoins]

if __name__ == "__main__":
    T = int(input())
    for k in range(T):
        N, J = [int(s) for s in input().split()]
        out = generate_jamcoins_and_proofs(N, J)
        print("Case #{0}:".format(k+1))
        for jamcoin, divisors in out:
            print(" ".join([str(jamcoin)] + [str(d) for d in divisors]))

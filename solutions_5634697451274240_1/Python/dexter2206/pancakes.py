"""Program calculating required pancacke flips."""

def calc_flips(s):
    if len(s) == 0:
        # no pancakes - no flips
        return s
    # the actual formula is pretty simple
    # count number of connected group of minuses
    # multiply by 2 and subtract 1 if string starts
    # from the minus. Or, calculate number of +-,
    # multiply by 2 and add 1 if string starts from -
    return s.count("+-") * 2 + (s[0] == "-")

if __name__ == "__main__":
    T = int(input())
    for k in range(T):
        S = input()
        print("Case #{0}: {1}".format(k+1, calc_flips(S)))

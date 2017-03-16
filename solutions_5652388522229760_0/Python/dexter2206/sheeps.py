

def get_output(N):

    if N == 0:
        return "INSOMNIA"
    digits = set(str(N))
    last = N
    k = 2
    while len(digits) != 10:
        last = N * k
        digits = digits.union(str(last))
        k = k + 1
    return last

if __name__ == "__main__":
    no_tests = int(input())
    for k in range(no_tests):
        N = int(input())
        print("Case #{0}: {1}".format(k+1, get_output(N)))

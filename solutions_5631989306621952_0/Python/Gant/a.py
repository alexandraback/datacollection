def abc(S):
    result = S[0];
    for c in S[1:]:
        if (c >= result[0]):
            result = c + result;
        else:
            result = result + c;
    return result;

if __name__ == "__main__":
    import sys
    with open(sys.argv[1]) as f:
        T = int(f.readline());
        for t in range(T):
            S = f.readline().strip();
            print "Case #{}: {}".format(t + 1, abc(S))


def abc(K, C, S):
    if K > C*S:
        return 'IMPOSSIBLE';

    positions = range(K);

    students = [0]*S;

    i = 0;
    while i*S < K:
        for j in range(S):
            if i*S + j < K:
                students[j] = students[j]*K + positions[i*S + j];
        i += 1;

    return ' '.join(map(str, [X+1 for X in students]));

if __name__ == "__main__":
    import sys
    with open(sys.argv[1]) as f:
        T = int(f.readline());
        for t in range(T):
            K, C, S = map(int, f.readline().split(' '))

            print "Case #{}: {}".format(t + 1, abc(K, C, S))


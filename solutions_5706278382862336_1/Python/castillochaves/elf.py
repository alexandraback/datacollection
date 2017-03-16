def solve(file):
    P, Q = (int(n) for n in file.readline().split('/'))
    gen = 0
    while P < Q:
        gen += 1
        P *= 2
    fix = 0
    left = P - Q
    while gen + fix <= 40 and left != 0:
        fix += 1
        left *= 2
        if left >= Q:
            left -= Q
    if left != 0:
        return "impossible"
    return "{}".format(gen)



test_answer = {
    1: "1",
    2: "1",
    3: "2",
    4: "impossible",
    5: "8",
}

if __name__ == '__main__':
    import sys
    test = False
    try:
        file_name = sys.argv[1]
    except IndexError:
        file_name = 'test.txt'
        test = True
    if len(sys.argv) > 1:
        file_name = sys.argv[1]
    with open(file_name) as f:
        T = int(f.readline())
        for i in range(1, T + 1):
            answer = solve(f)
            if test:
                assert answer == test_answer[i]
            else:
                print "Case #%d: %s" % (i, answer)

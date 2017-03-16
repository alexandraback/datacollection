import sys, os

min_abs = float('inf')
min_c, min_ci = None, None
min_j, min_ji = None, None

def main(C, J):
    global min_abs, min_c, min_ci, min_j, min_ji
    c = list(C)
    j = list(J)

    min_abs = float('inf')
    min_c, min_ci = None, None
    min_j, min_ji = None, None
    dfs(c, j, 0, 0, 0)

    return ''.join([str(z) for z in min_c]), ''.join([str(z) for z in min_j])

def dfs(c, j, ci, ji, i):
    global min_abs, min_c, min_ci, min_j, min_ji

    if i == len(c):
        new_abs = abs(ci - ji)
        if new_abs < min_abs:
            min_abs = new_abs
            min_c, min_ci = list(c), ci
            min_j, min_ji = list(j), ji
        elif new_abs == min_abs:
            if ci < min_ci or (ci == min_ci and ji < min_ji):
                min_c, min_ci = list(c), ci
                min_j, min_ji = list(j), ji
        return
            
    if c[i] != '?' and j[i] != '?':
        return dfs(c, j, ci * 10 + int(c[i]), ji * 10 + int(j[i]), i + 1)
    elif c[i] == '?' and j[i] != '?':
        #digits = [(10 + int(j[i]) - 1) % 10, int(j[i]), (int(j[i]) + 1) % 10]
        digits = list(range(10))

        ji = ji * 10 + int(j[i])
        for digit in digits:
            c[i] = digit
            dfs(c, j, ci * 10 + digit, ji, i+1)
            c[i] = '?'
    elif c[i] != '?' and j[i] == '?':
        #digits = [(10 + int(c[i]) - 1) % 10, int(c[i]), (int(c[i]) + 1) % 10]
        digits = list(range(10))

        ci = ci * 10 + int(c[i])
        for digit in digits:
            j[i] = digit
            dfs(c, j, ci, ji * 10 + digit, i+1)
            j[i] = '?'
    else:
        # both ?
        #digits = [0, 1, 9]
        digits = list(range(10))
        for digit1 in digits:
            c[i] = digit1
            new_ci = ci * 10 + digit1
            for digit2 in digits:
                j[i] = digit2
                dfs(c, j, new_ci, ji * 10 + digit2, i + 1)
                j[i] = '?'
            c[i] = '?'

if __name__ == "__main__":
    in_path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
    in_file = open(in_path, 'r')
    T = int(in_file.readline().rstrip())

    for case_idx in range(T):
        C, J = in_file.readline().rstrip().split()
        res = main(C, J)
        print("Case #{}: {} {}".format(case_idx + 1, res[0], res[1]))



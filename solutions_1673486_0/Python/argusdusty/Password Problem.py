import sys

def password_problem(A, B, p):
    prob_back = [1]
    C = A + B + 1
    D = C + B + 1
    exp_back = [C]
    for i in range(A):
        C -= 2
        D -= 2
        prob_back.append(prob_back[i]*p[i])
        exp_back.append(prob_back[-1]*C + (1-prob_back[-1])*D)
    return "%.6f" % min(min(exp_back), B + 2)

def main(filename):
    Input = open(filename, 'r').read().split('\n')
    Output = ""
    for i in range(1, int(Input[0])*2 + 1, 2):
        args = Input[i]
        A = int(args.split(' ')[0])
        B = int(args.split(' ')[1])
        args = Input[i+1]
        p = [float(j) for j in args.split(' ')]
        result = password_problem(A, B, p)
        Output += "Case #" + str(i//2 + 1) + ": " + result + "\n"
    open(filename[:-3] + ".out", 'w').write(Output)

if __name__ == "__main__": main(sys.argv[1])

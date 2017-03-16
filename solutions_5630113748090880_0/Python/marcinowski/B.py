def reader(file):
    f = open(file,'r')
    f_out = file[:-2]+"out"
    T = int(f.readline())
    cases = []
    for t in range(T):
        N = int(f.readline())
        case = []
        for n in range(2*N-1):
            line = f.readline().strip().split(' ')
            case.append(line)
        cases.append(case)
    return cases, f_out

def solver(cases, f_out):
    f_out = open(f_out,'w')
    for c in range(len(cases)):
        case = cases[c]
        N = len(case[0])
        a = []
        for row in case:
            for col in row:
                if col not in a:
                    a.append(col)
        a.sort()
        b = [0]*len(a)
        for el in range(len(a)):
            for row in case:
                b[el] += row.count(a[el])
        d = []
        for el in range(len(b)):
            if b[el]%2 != 0:
                d.append(int(a[el]))
        d.sort()
        #print(d)
        result = ''
        for k in d:
            result += str(k) + ' '
        #print("Case #{}: {}".format(c+1, result))
        print("Case #{}: {}".format(c + 1, result), file=f_out)
    f_out.close()

def main():
    cases, f_out = reader('B-small-attempt1.in')
    solver(cases, f_out)


main()

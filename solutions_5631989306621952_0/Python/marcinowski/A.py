def reader(file):
    f = open(file,'r')
    f_out = file[:-2]+"out"
    T = int(f.readline())
    cases = []
    for t in range(T):
        line = f.readline().strip()
        cases.append(line)
    return cases, f_out

def solver(cases, f_out):
    f_out = open(f_out,'w')
    for c in range(len(cases)):
        case = cases[c]
        result = []
        for i in case:
            if len(result)==0:
                result.append(i)
            elif i < result[0]:
                result.append(i)
            elif i >= result[0]:
                result.insert(0,i)
        result_str = ''
        for j in result:
            result_str += j
        #print("Case #{}: {}".format(c+1, result_str))
        print("Case #{}: {}".format(c+1, result_str), file=f_out)
    f_out.close()

def main():
    cases, f_out = reader('A-small-attempt1.in')
    solver(cases, f_out)

main()
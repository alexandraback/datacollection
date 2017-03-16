
def read_testcase(fname):
    testcase = [] 
    with open('{}.in'.format(fname), 'r') as f:
        t = f.readline()
        for i in range(int(t)):
            case = tuple(int(x) for x in f.readline().split())
            testcase.append(case)
    return testcase


def execute(case):
    r, c, w = case
        
    score = 0
    current_row = 1
    while 1:
        if current_row == r:
            bound = c - w
            partition_a, remainder = divmod(bound, w)

            score += partition_a
            if remainder > 0:
                score += 1
            score += w
            return score
        else:
            current_row += 1
            score += c // w

    
    

def save(result, fname):
    with open('{}.out'.format(fname), 'w') as fname:
        for i, out in enumerate(result):
            print("Case #{}: {}".format(i+1, out), file=fname)

    
def main():
    fname = "a"
    testcase = read_testcase(fname)
    result = [execute(case) for case in testcase]
    save(result, fname)

if __name__ == '__main__':
    main()

import sys
import functools

def read_case(lines):
    splited = lines.split()
    n = int(splited[0])
    suprising = int(splited[1])
    p = int(splited[2])
    results = splited[3: 3 + n]
    results = [int(i) for i in results]
    assert len(results) == n
    
    return (suprising, p, results)


def read_input(path):
    cases = []
    with file(path) as f:
        lines = iter(f)
        n = int(lines.next())

        for i in range(1, 1 + n):
            cases.append((i, read_case(lines.next())))

    return cases


def could_be_suprising(value):
    return value >=2 and value <=28

def solve(case):
    suprising, p, results = case
    
    pass_p = 0
    for i in results:
        max_value = (i // 3)
        delta = 1 if i % 3 > 0 else 0
        max_value += delta
        
        if max_value >= p:
            pass_p += 1
            continue
        if could_be_suprising(i) and suprising > 0:
            if i % 3 != 1 and max_value + 1 >= p:
                suprising -= 1
                pass_p += 1
                
    return pass_p
            
if __name__ == '__main__':
    cases = read_input(sys.argv[1])
    for i, case in cases:
        print 'Case #%d: %s' % (i, solve(case))

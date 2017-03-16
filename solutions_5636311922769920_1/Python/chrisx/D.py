from itertools import zip_longest

def parse(input_file, output_file):
    with open(input_file) as f:
        T = int(f.readline().split()[0])
        out = open(output_file, 'w')
        for i in range(T):
            K, C, S = map(int, f.readline().split())
            sol = solve(K, C, S)
            sol = " ".join(map(str, sol))
            line = "Case #"+str(i+1)+": "+str(sol)
            print(line)
            out.write(line+'\n')
    return


def solve(K, C, S):
    if C*S < K:
        return ['IMPOSSIBLE']
    sol = []
    if K % C == 0:
        min_set_needed = K//C
    else:
        min_set_needed = K//C + 1
    assert S >= min_set_needed
    l = list(zip_longest(list(range(K)), list(range(C))*min_set_needed, fillvalue=0))
    assert len(l) == C*min_set_needed
    pos = 0
    for bit, order_in_set in l:
        if order_in_set != 0:  # starting a new set
            pos *= K
        pos += bit
        if order_in_set == C-1:
            sol.append(pos+1)
            pos = 0

    assert len(set(sol)) == len(sol)
    assert len(sol) <= S

    return sol
        




dir = "./"

input_file = dir+"D-test.txt"
output_file = dir+"D-test.out.txt"

input_file = dir+"D-small-attempt0.in"
output_file = dir+"D-small-attempt0.txt"

input_file = dir+"D-large.in"
output_file = dir+"D-large.txt"

'''
'''
parse(input_file, output_file)


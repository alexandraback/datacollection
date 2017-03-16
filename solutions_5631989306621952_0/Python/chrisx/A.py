from itertools import zip_longest

def parse(input_file, output_file):
    with open(input_file) as f:
        T = int(f.readline().split()[0])
        out = open(output_file, 'w')
        for i in range(T):
            S = f.readline().split()[0]
            sol = solve(S)
            line = "Case #"+str(i+1)+": "+str(sol)
            print(line)
            out.write(line+'\n')
    return


def solve(S):
    makschar = [None]*len(S)
    for ind, char in enumerate(S):
        if ind == 0:
            makschar[ind] = ord(char)
            continue
        makschar[ind] = max(makschar[ind-1], ord(char))
    # leftright = ['-']*len(S)
    left = []
    right = []
    for ind in range(len(S)-1,-1,-1):
        if ord(S[ind]) == makschar[ind]:  # put to left
            left.append(S[ind])
        else:
            right.append(S[ind])
    return ''.join(left)+''.join(right[::-1])




dir = "./"

'''
input_file = dir+"A-test.txt"
output_file = dir+"A-test.out.txt"

'''
input_file = dir+"A-small-attempt0.in"
output_file = dir+"A-small-attempt0.txt"

'''
input_file = dir+"A-large.in"
output_file = dir+"A-large.txt"

'''
parse(input_file, output_file)



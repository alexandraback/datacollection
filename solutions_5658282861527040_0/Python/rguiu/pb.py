problem = "B"
case = "small" # "small" "large"

input_file  = "%s-%s.in" % (problem,case)
output_file = "%s-%s.out" % (problem,case)


with open(input_file, 'r') as inputf, open(output_file, 'w') as outputf:
    lines = inputf.readlines()
    N = int(lines.pop(0))
    for i in range(0,N,1):
        # do something
        A,B,K  = map(int,lines[i].split(' '))
        print A,B,K
        va = 0
        for x in range(A):
            for y in range(B):
                if ((x&y)<K):
                    va = va + 1
        outputf.write("Case #%s: %s\n" % (i+1, va))

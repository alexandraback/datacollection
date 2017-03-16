##input = open('A-sample-input.txt', 'r')
##output = open('A-sample-output.txt', 'w')

input = open('A-small-attempt0.in', 'r')
output = open('A-small.out', 'w')

##input = open('A-large.in', 'r')
##output = open('A-large.out', 'w')

table = [0] *1000001

def switch(n):
    s = str(n)
##    print s
    s = s[::-1]
##    print s
    return int(s)
##print switch(120)

def build():
    for i in range(1,1000001):
##        if i % 1000 == 0:
##            print i
        if i < 21:
            table[i] = i
        else:
            if switch(i) >= i or i % 10 == 0:
                table[i] = table[i - 1] + 1
            else:
                table[i] = min(table[i - 1] + 1, table[switch(i)] + 1)
##        print 'i=', i, 'table=',table[i]

build()
##print table[638]
##print table[99]

def read_int():
    return int(input.readline().strip())

def read_ints():
    return [int(x) for x in input.readline().split()]

def read_float():
    return float(input.readline().strip())

def read_floats():
    return [float(x) for x in input.readline().split()]

def solve(n):
    return table[n]

def main():
    num_cases = read_int()
    for case in range(1, num_cases+1):
        n = read_int()
##        if case == 1:
        solution = solve(n)
        solution_string = "Case #%d: %s" %(case, solution)
        output.write(solution_string + "\n")
        print solution_string
        

main()
input.close()
output.close()
    

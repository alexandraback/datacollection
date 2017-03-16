##input = open('C-sample-input.txt', 'r')
##output = open('C-sample-output.txt', 'w')

input = open('C-small-attempt0.in', 'r')
output = open('C-small.out', 'w')

##input = open('C-large.in', 'r')
##output = open('C-large.out', 'w')


    
def is_pal(n):
    n = str(n)
    if len(n) < 2:
        return True
    return n[0] == n[-1] and is_pal(n[1:-1])

answers = []
for i in range(1, int(1000 ** 0.5) + 1):
    if is_pal(i):
        if is_pal(i*i):
            answers.append(i*i)

    
def solve(A, B):
    i = 0
    while i < len(answers) and answers[i] < A:
        i += 1
    if i == len(answers):
        return 0
    j = i
    while j < len(answers) and answers[j] <= B:
        j += 1
    return j-i
        
        

def main():
    num_cases = int(input.readline().strip())
    for case in range(1, num_cases+1):
        A, B = [int(x) for x in input.readline().split()]
        solution = solve(A, B)
        solution_string = "Case #%d: %s" %(case, solution)
        output.write(solution_string + "\n")
        print solution_string
        

main()
input.close()
output.close()
    

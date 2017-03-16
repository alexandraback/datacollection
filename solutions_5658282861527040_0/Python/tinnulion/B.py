import math

def solve(input_file):
    case = input_file.readline().split(' ')
    A = int(case[0])
    B = int(case[1])
    K = int(case[2])
    print A, B, K

    if min(A, B) <= K:
        return A * B

    count = A * K + B * K - K * K

    for a in xrange(K, A):
        for b in xrange(K, B):
            if a & b < K:
                count += 1
    return count

input_file = open('B.in', 'r')
output_file = open('B.out', 'w')

number_of_cases = int(input_file.readline())
print 'number_of_cases:', number_of_cases

for i in xrange(number_of_cases):
    solution = solve(input_file)
    output_str = 'Case #' + str(i + 1) + ': ' + str(solution)
    print output_str
    output_file.write(output_str + '\r\n')

print "Done!!!"

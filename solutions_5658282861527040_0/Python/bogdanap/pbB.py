input = open('input', 'r')
output = open('output', 'w')

testcases = int(input.readline().strip())
for testcase in xrange(1, testcases+1):
    a,b,k = input.readline().strip().split(' ')
    result = 0
    for i in xrange(int(a)):
        for j in xrange(int(b)):
            if i & j < int(k):
                result +=1
    output.write("Case #%s: %d\n" % (testcase, result))

input.close()
output.close()

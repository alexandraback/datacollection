f = open('A-large.in')
#f = open('test.in')
count = int(f.readline())
output = ''
for x in xrange(1, count + 1):
    arr = f.readline().split()
    R = int(arr[0])
    C = int(arr[1])
    W = int(arr[2])
    mod = C % W
    if mod == 0:
        ret = C / W * R + W - 1
    else:
        ret = C / W * R + W
    output += 'Case #' + str(x) + ': ' + str(ret) + '\n'

print(output)
newf = open('output.txt','w')
newf.write(output)

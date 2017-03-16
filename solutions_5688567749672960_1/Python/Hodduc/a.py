T = input()
s = [1, 10]
for i in range(2, 17):
    if i % 2 == 0:
        #print s, s[-1], (10**(i/2))*2
        s.append(s[-1] + (10**(i/2)) * 2 - 1)
    else:
        #print s, s[-1], (10**(i/2) )*2
        s.append(s[-1] + (10**(i/2)) + (10**(i/2+1)) - 1)

for C in range(1, T+1):
    num_s = raw_input()
    l = len(num_s)
    if l == 1:
        print "Case #%d:" % C, num_s
        continue
    addition = 0
    left = int(num_s[:l/2][::-1])
    right = int(num_s[l/2:])

    if right == 0:
        num_s = str(int(num_s)-1)
        l = len(num_s)
        if l == 1:
            print "Case #%d:" % C, int(num_s)+1
            continue
        addition = 1
        left = int(num_s[:l/2][::-1])
        right = int(num_s[l/2:])

    base = s[len(num_s)-1] + addition

    if num_s[0] == '1':
        print "Case #%d:" % C, base+min(left+right, int(num_s[1:]))
    else:
        print "Case #%d:" % C, base+left+right

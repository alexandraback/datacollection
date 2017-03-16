__author__ = 'z_bodya'

#f = open('b_in.txt', 'r')
f = open('B-small-attempt0.in', 'r')
o = open('b_out.txt', 'w')
t = int(f.readline())
for test in range(t):
    line = [int(i) for i in f.readline().split(' ')]
    n, s, p = line[0], line[1], line[2]
    items = line[3:]
    o.write('Case #' + str(test + 1) + ': ')
    ans = 0
    for i in items:
        tv = i / 3
        ov = i % 3
        if tv + (ov>0)>= p:
            ans += 1
            continue
        if (tv+ov>=p or (tv+1>=p and tv>0)) and s>0:
            s -=1
            ans+=1
            continue
    o.write(str(ans)+"\n")
f.close()
o.close()
f = open('/Users/shivamahajan/Desktop/file.txt' , 'r')
ff = open('/Users/shivamahajan/Desktop/output.txt' , 'w')
import os

for i in xrange(int(f.readline().split()[0])):
    c,ft,x = [float(x) for x in f.readline().split()]
    time = 0.0
    cur_rate = 2.0
    while 1:
        time1 = c/cur_rate
        time2 = x/(cur_rate+ft)
        time3 = x/cur_rate
        if time1+time2 < time3:
            time += time1
            cur_rate += ft
        else:
            time+=time3
            break
            
    ans = "%.7f" %time        
    ff.write("Case #" + str(i+1) + ": "+ str(ans)+ os.linesep)
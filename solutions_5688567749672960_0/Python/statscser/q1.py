import os
os.chdir('C:\\Users\Xueying\Desktop\Google Code Jam 2015\Round1B')

filename = 'a_in.txt'
out = open('a_out.txt', 'w')

dict = {2:11, 3:30, 4:139, 5:339, 6:1439, 7:3440}

with open(filename, 'r') as f:
    case = int(f.readline())
    for i in range(0, case):
        n = int(f.readline())
        if n <= 11:
            num = n
        else:
            # flip twice
            l = len(str(n))
            fp = str(n)[0:l/2]
            rfp = int(fp[::-1])
            lp = int(str(n)[l/2:l])
            num1 = dict[l] + rfp + lp   
            
            # flip once
            
                              
            # not flip
            num2 = dict[l] + n % 10**(l-1) - 1
            num = min(num1, num2)
            
        print(num)
        out.write('Case #' + str(i+1) + ': ' + str(num) + '\n')
    out.close()
f.close()
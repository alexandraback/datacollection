f1=open('C:/Python27/gaben', 'w+')

linelist = []
for line in open('C:\Users\User\Downloads\A-large.in'):
    linelist.append(line.rstrip('\n'));

testnum = int(linelist[0]);

a = 2.0**40

for i in xrange(testnum):
    number = linelist[i+1]
    slash = number.index('/')
    top = float(number[:slash])
    bot = float(number[slash+1:])
    num = top/bot
    q = a*num
    if q%1 != 0:
        f1.write("Case #"+str(i+1)+": impossible\n")
    else:
        gen = 0
        while True:
            test = q - a/(2.0**gen)
            if test%1 == 0 and test >= 0:
                break
            else:
                gen += 1
        #binstring = str(bin(int(q)))[2:]
        
        #while binstring[-1] == '0':
        #    binstring = binstring[:-1]
        #    gen -= 1
        f1.write("Case #"+str(i+1)+": "+str(gen)+"\n")



f1.close()

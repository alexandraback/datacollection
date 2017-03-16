import codecs

with codecs.open('A-large.in','r','utf-8') as f:
    test_cases = int(f.readline().strip())
    for t in range(test_cases):
        print "Case #%i:" % (t+1),
        data = f.readline().strip().split('/')
        if(int(data[1]) % 2 == 1 or float(data[0])/float(data[1]) < (1/(2 ** 40))):
            print "impossible"
        else:
            cnt = 0
            cnt_out = 0
            root_val = int(data[0])
            while(True):
                root_val *= 2
                cnt += 1
                if(root_val == int(data[1])):
                    print "%i" % cnt
                    break
                elif(root_val > int(data[1])):
                    cnt_out = cnt
                    root_val -= int(data[1])
                    while cnt <= 40:
                        root_val *= 2
                        cnt += 1
                        if(root_val % int(data[1]) == 0):
                            print "%i" % cnt_out
                            break
                    if(root_val % int(data[1]) != 0):
                        print "impossible"
                        break
                    break
f = open('C-small-attempt1.in', 'r');
f2 = open('resultSmall1.txt', 'w');

T = f.readline();

for t in range(0, int(T)):
    line = f.readline().strip('\n')
    nums = line.split(' ')

    J = int(nums[0])
    P = int(nums[1])
    S = int(nums[2])
    K = int(nums[3])

    #print J,P,S,K,'\t',(str(J*P*S))

    c1 = []
    c2 = []
    c3 = []

    combis = 0
    output = []

    for j in range(0, J):
        for p in range(0, P):

            for s in range(S-1, -1, -1):

                #print j, p, s

                comb1 = str(j) + str(p)
                comb2 = str(p) + str(s)
                comb3 = str(j) + str(s)

                count1 = c1.count(comb1)
                count2 = c2.count(comb2)
                count3 = c3.count(comb3)

                if count1 < K and count2 < K and count3 < K:
                    combis += 1
                    output.append(str(j+1) + " " + str(p+1) + " " + str(s+1))
                    c1.append(comb1)
                    c2.append(comb2)
                    c3.append(comb3)

    #print combis
    #print c2
    #print c3
    
    f2.write("Case #" + str(t+1) + ": " + str(combis) + '\n')
    for l in output:
        f2.write(l + '\n')
   
f.close()
f2.close()

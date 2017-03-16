from sets import Set

t = int(input())
for i in range(1, t + 1):
    input_line = raw_input()
    K, C, S = input_line.split(" ")
    K = int(K)
    C = int(C)
    S = int(S)
    output = ""

    if S < K/C:
        output = " IMPOSSIBLE"

    else:
        #print("K", K)
        #print("C", C)
        #print("S", S)
        for j in range(1, K+1):
            output += " " + str(j)


        #for j in range(0, (K+C-1)/C):

        #if (K+C-1)/C == 1:
            #print("This one is right")
        #    postion = 1
        #    for z in range(0, C-1):
                #print(z)
        #        postion += (K-(z+1)) * (K**z)

        #    output += str(postion)
            #print( " ",((K-(z+1)) * (K**z)) )

        #if (K + C - 1) / C == 2:
        #    print("check2")
        #    postion = 1
        #    for z in range(0, C - 1):
                # print(z)
        #        postion += (K - (z + 1)) * (K ** z)

#            output += str(postion)
 #           output += " "
  #          postion = ((2*K)) + postion + 1
   #         output += str(postion)

            #postion += K**(z-1)
            #print(postion)


    print("Case #{}:{}".format(i, output))

"""
comments
for each value of C we

"""
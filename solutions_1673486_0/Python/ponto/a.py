import math
import sys

enter = 1
backspace=1

num = raw_input()


for i in range(int(num)):
    line = raw_input()
    ar =  line.split(" ")
    a = int(ar[0])
    b = int(ar[1])
    line2 = raw_input()
    prob = line2.split(" ")

    # keep typing
    c_prob = 1
    for x in prob:
        c_prob = c_prob * float(x)

    min_val = (1-c_prob)*(b-a+enter+b+enter) + c_prob*(b-a+enter)

    #right away
    min_val = min(min_val, b+enter+enter)

    # type backspace j+1
    for j in range(a):
        cost = backspace*(j+1) + (b-a+(j+1)) + enter
        cost_bad = cost + b + enter
        co_prob = 1
        for k in range(a-j-1):
            #print prob[a-k-1]
            co_prob = co_prob * float(prob[k])
        min_val = min(min_val, cost*co_prob + cost_bad *(1-co_prob))
    print "Case #"+str(i+1)+": "+str(round(min_val,6))

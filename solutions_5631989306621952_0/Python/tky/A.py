# Google code jam
import numpy as np


alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

# read number of cases from stdin    
T = int(input()) 

for j in range(1,T+1):

    S = input() #  read in string

    word = S[0]
    i = alph.find(S[0])

    for s in S[1::]:
        if alph.find(s) >= i:
            word = s + word
        else:
            word = word + s
        i = alph.find(word[0])
        
    print("Case #{}: {}".format(j,word))

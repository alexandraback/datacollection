import os
import sys
from random import randrange

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

input_file = open("input.in")
input_data = input_file.read()
input_file.close()

input = input_data.split('\n')
T = int(input[0])
input = input[1:]
R, N, M, K = map(int,input[0].split(' '))
input = input[1:]

class cards:
    def __init__(self,N,M,K,prod):
        self.N,self.M,self.K,self.prod = N,M,K,prod
        self.cards=[]
    def five(self):
        if filter(lambda x:x%125 == 0, self.prod):
            self.cards += [5, 5, 5]
            return
        elif filter(lambda x:x%25 == 0, self.prod):
            self.cards += [5,5]
        elif filter(lambda x:x%5 == 0, self.prod):
            self.cards += [5]
        if filter(lambda x:x%27 == 0, self.prod):
            self.cards += [3,3,3]
            return
        elif filter(lambda x:x%9 == 0,self.prod):
            self.cards += [3,3]
        elif filter(lambda x:x%3 == 0, self.prod):
            self.cards += [3]
        if filter(lambda x:x%4 == 0,self.prod):
            if len(self.cards) >= 2:
                self.cards+= [4]
                return
            else:
                self.cards += [2,2]
        elif filter(lambda x:x%2 == 0, self.prod):
            self.cards += [2]
        while len(self.cards)<3:
            self.cards += [randrange(2,self.M+1)]
    def eight(self):
        if filter(lambda x:x%int(7**12) == 0, self.prod):
            self.cards += [7,7,7,7,7,7,7,7,7,7,7,7]
            return
        if filter(lambda x:x%int(5**12) == 0, self.prod):
            self.cards += [5,5,5,5,5,5,5,5,5,5,5,5]
            return
        if filter(lambda x:x%int(3**12) == 0, self.prod):
            self.cards += [3,3,3,3,3,3,3,3,3,3,3,3]
            return
        if filter(lambda x:x%int(8**12) == 0, self.prod):
            self.cards += [8,8,8,8,8,8,8,8,8,8,8,8]
            return
        for i in range(1,12):
            if filter(lambda x:x%int(7**i)==0,self.prod):
                self.cards += [7]
            if filter(lambda x:x%int(5**i)==0,self.prod):
                self.cards += [5]
        for i in range(7,12):
            if filter(lambda x:x%int(8**i)==0,self.prod):
                self.cards += [8]
        if filter(lambda x:x%8 == 4, self.prod):
            if len(self.cards)<=10:
                if randrange(1,3)<2:
                    self.cards += [2,2]
                else:
                    self.cards += [4]
            else:
                self.cards += [4]
        
        if filter(lambda x:x%4 == 2, self.prod):
            if not filter(lambda x:x==2, self.prod):
                self.cards += [2]
                
        for i in range(1,12):
            if filter(lambda x:x%int(6**i)==0,self.prod):
                if len(self.cards)<=10:
                    if randrange(1,3)<2:
                        self.cards += [2,3]
                    else:
                        self.cards += [6]
                else:
                    self.cards += [6]
        while len(self.cards)<12:
            self.cards += [randrange(2,self.M+1)]

result = []
input_data = []
for i in range(R):
    input_data += [cards(N,M,K,map(int,input[0].split(' ')))]
    input = input[1:]
    input_data[i].eight()
    result += [input_data[i].cards]

output_data='Case #1:\n'
for i in range(R):
    for card in result[i]:
        output_data+=str(card)
    output_data+='\n'
output_file = open("output.txt",'w')
output_file.write(output_data)
output_file.close()
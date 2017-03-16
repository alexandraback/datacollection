def rank(file):
    ans = ''
    for i in range(0,len(file)):   
        if file[i] == 1:
            ans = ans + " " + str(i)
    return ans



def main():
    length = int(input())
    ans = []
    for i in range(0,length): 
        file = [0]*2600
        n = int(input())
        for j in range(0, 2*(n-1)+1):
            line = input()
            line = line.split()
            for number in line:
                index = int(number)
                file[index] += 1
                file[index] = int(file[index]%2)
        ans += [rank(file)]  
            
    for i in range(0,length):
       line = ''
       line += "Case #" + str(i+1) + ": " + ans[i]
       #for var in ans[i]:
       #    line += str(var)
       print(line)

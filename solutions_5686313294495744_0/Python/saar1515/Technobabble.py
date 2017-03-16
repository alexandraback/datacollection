from random import shuffle

def maxFakes(lst):
    maxnum =0
    for i in range(6000):
        shuffle(lst)
        maxnum=max(maxnum,numOfFakes(lst))
    return maxnum

def numOfFakes(lst1):
    lst=lst1[:]
    for i in range(len(lst)):
        lst[i]=lst[i].split(" ")
    counter =0
    fCounter = 0
    sCounter = 0
    sWord=""
    fWord=""
    i = 0
    j=0
    length=len(lst)

    while i < length:
        fWord = lst[i][0]
        sWord = lst[i][1]
        j=0
        while j <(length):
            if(fWord == lst[j][0]):
                fCounter += 1
            if(sWord == lst[j][1]):
                sCounter += 1
            if(fCounter>1 and sCounter>1):
                counter+=1
                break
            j+=1
        if(fCounter>1 and sCounter>1):
            del lst[i]
            length-=1
        else:
            i+=1
        fCounter = 0
        sCounter = 0
    return counter

def readFile(path=r"C:\Users\Saar\Desktop\ap.txt"):
    with open(path,'r') as f:
        lst=f.read().splitlines()
    return lst

if __name__ == '__main__':
    file=readFile(r"C:\Users\Saar\Desktop\C-small-attempt1.in")
    del file[0]
    del file[0]
    lst=[]
    length = len(file)
    counter = 1

    for i in range(length):
        if file[i].isdigit():
            print("Case #"+str(counter)+": "+str(maxFakes(lst)))
            counter+=1
            lst=[]
        else:
            lst.append(file[i])
    print("Case #"+str(counter)+": "+str(maxFakes(lst)))
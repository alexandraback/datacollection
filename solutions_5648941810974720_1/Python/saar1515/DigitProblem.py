

def readFile(path=r"C:\Users\Saar\Desktop\ap.txt"):
    with open(path,'r') as f:
        lst=f.read().splitlines()
    return lst

def deleteNumOfOccurences(string, charec, number):
    str=""
    number = string.count(charec)-number

    for letter in string:
        if(letter==charec):
            if number>0:
                str+=letter
                number-=1
        else:
            str+=letter
    return str

def numbersa(zero, one, two, three, four, five, six, seven, eight, nine):
    str=""
    str+="0"*zero
    str+="1"*one
    str+="2"*two
    str+="3"*three
    str+="4"*four
    str+="5"*five
    str+="6"*six
    str+="7"*seven
    str+="8"*eight
    str+="9"*nine
    return str

def zeros(string):
    counter = string.count('Z')
    string = deleteNumOfOccurences(string,"Z",counter)
    string = deleteNumOfOccurences(string,"E",counter)
    string = deleteNumOfOccurences(string,"R",counter)
    string = deleteNumOfOccurences(string,"O",counter)
    return (counter,string)

def ones(string):
    counter = string.count('O')
    string = deleteNumOfOccurences(string,"O",counter)
    string = deleteNumOfOccurences(string,"N",counter)
    string = deleteNumOfOccurences(string,"E",counter)
    return (counter,string)

def twos(string):
    counter = string.count('W')
    string = deleteNumOfOccurences(string,"W",counter)
    string = deleteNumOfOccurences(string,"T",counter)
    string = deleteNumOfOccurences(string,"O",counter)
    return (counter,string)

def threes(string):
    counter = string.count('R')
    string = deleteNumOfOccurences(string,"R",counter)
    string = deleteNumOfOccurences(string,"T",counter)
    string = deleteNumOfOccurences(string,"H",counter)
    string = deleteNumOfOccurences(string,"E",counter)
    string = deleteNumOfOccurences(string,"E",counter)
    return (counter,string)

def fours(string):
    counter = string.count('U')
    string = deleteNumOfOccurences(string,"U",counter)
    string = deleteNumOfOccurences(string,"F",counter)
    string = deleteNumOfOccurences(string,"O",counter)
    string = deleteNumOfOccurences(string,"R",counter)
    return (counter,string)

def fives(string):
    counter = string.count('F')
    string = deleteNumOfOccurences(string,"F",counter)
    string = deleteNumOfOccurences(string,"I",counter)
    string = deleteNumOfOccurences(string,"V",counter)
    string = deleteNumOfOccurences(string,"E",counter)
    return (counter,string)

def sixes(string):
    counter = string.count('X')
    string = deleteNumOfOccurences(string,"X",counter)
    string = deleteNumOfOccurences(string,"S",counter)
    string = deleteNumOfOccurences(string,"I",counter)
    return (counter,string)

def sevens(string):
    counter = string.count('V')
    string = deleteNumOfOccurences(string,"V",counter)
    string = deleteNumOfOccurences(string,"S",counter)
    string = deleteNumOfOccurences(string,"E",counter)
    string = deleteNumOfOccurences(string,"E",counter)
    string = deleteNumOfOccurences(string,"N",counter)
    return (counter,string)

def eights(string):
    counter = string.count('G')
    string = deleteNumOfOccurences(string,"G",counter)
    string = deleteNumOfOccurences(string,"E",counter)
    string = deleteNumOfOccurences(string,"I",counter)
    string = deleteNumOfOccurences(string,"H",counter)
    string = deleteNumOfOccurences(string,"T",counter)
    return (counter,string)

def nines(string):
    counter = string.count('E')
    string = deleteNumOfOccurences(string,"E",counter)
    string = deleteNumOfOccurences(string,"I",counter)
    string = deleteNumOfOccurences(string,"N",counter)
    string = deleteNumOfOccurences(string,"N",counter)
    return (counter,string)

def stringToNumber(string):
    zero,string = zeros(string)
    two,string = twos(string)
    six,string = sixes(string)
    four,string = fours(string)
    one,string = ones(string)
    five,string = fives(string)
    seven,string = sevens(string)
    eight,string = eights(string)
    three,string = threes(string)
    nine,string = nines(string)
    return numbersa(zero,one,two,three,four,five,six,seven,eight,nine)

if __name__ == '__main__':
    file=readFile(r"C:\Users\Saar\Desktop\A-small-attempt2.in")
    del file[0]
    counter = 1
    for item in file:
        print("Case #"+str(counter)+": "+str(stringToNumber(item)))
        counter+=1
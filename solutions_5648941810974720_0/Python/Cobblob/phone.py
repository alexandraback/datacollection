from random import shuffle

def checkNumber(s, number):
    runs = 0
    while 1:
        #print s, number
        news = s
        for l in number:
            if l not in news:
                return s, runs
            else:
                news = news.replace(l, "", 1)
        s = news
        runs += 1



def solve(s):
    news = s.replace("\n", "")
    numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    numbersT = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
    shuffle(numbers)
    digits = ""
    for i, number in enumerate(numbers):
        news, runs = checkNumber(news, numbersT[number])
        for x in range(runs):
            digits += str(number)
    if (len(news) > 0):
        return solve(s)
    return ''.join(sorted(digits))



def main():
    f = open("A-small-attempt0.in", 'r')
    lines = f.readlines()
    f.close()

    outFile = open("out.txt", 'w')
    for i, n in enumerate(lines[1:]):
        out = "Case #"+str(i + 1)+": " + str(solve(n))+"\n"
        outFile.write(str(out))


main()

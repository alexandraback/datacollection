def last(word):
    ans = word[0]
    word = word[1:]
    for character in word:
        if character < ans[0]:
            ans = ans + character
        else:
            ans = character + ans
    return ans



def main():
    length = int(input())
    ans = []
    for i in range(0,length):
        ans += [last(input())]

    for i in range(0,length):
       line = ''
       line += "Case #" + str(i+1) + ": "
       for var in ans[i]:
           line += str(var)
       print(line)

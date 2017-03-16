def lastWord(word):
    output = word[0]
    for letter in list(word[1:]):
        if letter >= output[0]:
            output = letter + output
        else:
            output = output + letter
    return output

for i in range(1,int(input())+1):
    word = input()
    print('Case #{}: {}'.format(i,lastWord(word)))
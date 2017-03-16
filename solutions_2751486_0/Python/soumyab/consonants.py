if __name__ == '__main__':
    T = int(input())
    vowels = 'aeiou'
    for i in range(T):
        line = input().split()
        n = int(line[1])
        string = line[0]
        length = len(string)
        n_value = 0
        valid_nstrings = list()
        for index in range(len(string)-n+1):
            substring = string[index:index+n]
            vowel = False
            for letter in substring:
                if letter in vowels:
                    vowel = True
                    break
            if not vowel:
                valid_nstrings.append(substring)
        for first in range(len(string)):
            for second in range(first, len(string)):
                for thing in valid_nstrings:
                    if thing in string[first:second+1]:
                        n_value += 1
                        break
        print("Case #" + str(i+1) + ": " + str(n_value))

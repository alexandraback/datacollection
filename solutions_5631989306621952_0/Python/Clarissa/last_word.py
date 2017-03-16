# Time to get the last word in!
import fileinput

def find_last_word(string):
    # Finds the last word for a given string.
    last_word = ''
    max_ordinance_so_far = -1;
    for letter in string:
        # Letter is as big as the biggest seen, put in front
        if ord(letter) >= max_ordinance_so_far:
            max_ordinance_so_far = ord(letter)
            last_word = letter + last_word
        #Letter is smaller than biggest seen, put in back
        else:
            last_word = last_word + letter
    
    return last_word;

def main():
    firstLine = True
    case = 1
    for line in fileinput.input():
        if firstLine:
            firstLine = False
            continue

        word = line.strip()
        print('Case #' + str(case) + ': ', end="")
        print(find_last_word(word))
        case += 1

if __name__ == '__main__':
    main()

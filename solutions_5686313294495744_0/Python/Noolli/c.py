
def solve(words):
    first_words = {}
    second_words = {}
    for i in range(len(words)):
        w = words[i]
        if w[0] not in first_words.keys():
            first_words[w[0]] = []
        first_words[w[0]].append(i)

        if w[1] not in second_words.keys():
            second_words[w[1]] = []
        second_words[w[1]].append(i)

    no_f = True
    no_s = True
    for indexes in first_words.values():
        if len(indexes)> 1:
            no_f = False
            break
    for indexes in second_words.values():
        if len(indexes)>1:
            no_s = False
            break
    if no_s or no_f:
        return "0"

    to_return = 0
    for f in first_words.keys():
        indexes = first_words[f]
        if len(indexes) > 1:
            for index in indexes:
                s = words[index][1]
                if len(second_words[s])> 1:
                    to_return += 1

    return str(to_return)



def main():
    input_file = open('C-small-attempt0.in', 'r')
    output_file = open('C-small.out', 'w')
    number_of_cases = int(input_file.readline().strip())
    for i in range(1, number_of_cases + 1):
        v = int(input_file.readline().strip())
        words = []
        for j in range(v):
            words.append(input_file.readline().strip().split(" "))
        result = solve(words)
        print result
        output_file.write("Case #" + str(i) + ": " + result + "\n")

    input_file.close()



if __name__ == "__main__":
    main()
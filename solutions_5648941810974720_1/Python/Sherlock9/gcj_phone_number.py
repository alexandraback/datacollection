def phone_number():

    with open("A-large.in") as file:
        lines = file.readlines()

    cases = []

    for index, test in enumerate(lines[1:]):

        a = {0:"ZERO", 2:"TWO", 4:"FOUR", 6:"SIX", 8:"EIGHT",
             1:"ONE", 3:"THREE", 5:"FIVE", 7:"SEVEN", 9:"NINE"}

        test = list(test.strip())

        result = []

        for i, j in enumerate("Z W U X G"):
            while test.count(j) > 0:
                result.append(str(i))
                for char in a[i]:
                    test.remove(char)

        for i, j in enumerate(" O H F S"):
            while test.count(j) > 0:
                result.append(str(i))
                for char in a[i]:
                    test.remove(char)

        while test:
            result.append("9")
            for char in a[9]:
                test.remove(char)

        result = ''.join(sorted(result))

        cases.append("Case #{}: {}\n".format(index+1, result))

    with open("A-large.out", 'w') as file:
        for string in cases:
            file.write(string)

phone_number()

from sets import Set

t = int(input())
for i in range(1, t + 1):
    inputted_number = int(input())

    if inputted_number == 0:
        last_number = "INSOMNIA"


    else:
        current_number = inputted_number
        seen_numbers = Set()
        times = 1
        check = False
        while(check == False):
            string_number = str(current_number)
            last_number = current_number
            for j in string_number:
                seen_numbers.add(j)
            if len(seen_numbers) == 10:
                check = True
            times += 1
            current_number = inputted_number * times

    print("Case #{}: {}".format(i, last_number))

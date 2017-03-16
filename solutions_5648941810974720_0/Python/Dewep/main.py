#!/usr/bin/env python3

T = int(input())

digits = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

def find_number(number):
    for digit in range(0, len(digits)):
        try:
            new_number = str(number)
            for c in digits[digit]:
                index = new_number.index(c)
                if len(new_number) == 1:
                    new_number = ""
                else:
                    new_number = new_number[:index] + new_number[index + 1:]
            if len(new_number) == 0:
                return str(digit)
            next_number = find_number(new_number)
            if next_number:
                return str(digit) + next_number
        except:
            pass
    return None

for t in range(0, T):
    number = input()
    print("Case #%d:" % (t + 1), find_number(number))

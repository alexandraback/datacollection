from fractions import Fraction
import math

def is_power_of_two(number):
    return number & number - 1 == 0

def main():
    num_cases = int(input())
    for case in range(1, num_cases + 1):
        vida = Fraction(input())

        answer = "impossible"
        if is_power_of_two(vida.denominator):
            answer = 1
            test = Fraction(1, 2)
            while vida < test:
                answer += 1
                test /= 2

        
        print("Case #{}: {}".format(case, answer))

if __name__ == '__main__':
    main()

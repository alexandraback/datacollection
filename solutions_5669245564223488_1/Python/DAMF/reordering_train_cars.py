#!/usr/bin/python

import sys

def factorial( n ):
    if n == 0:
        return 1
    else:
        return (n*factorial(n-1))%1000000007


def nchoosek( n, k ):
    #return factorial(n)/(factorial(k)*factorial(n-k))
    answer = 1
    for i in range(1,k+1):
        answer *= (n - (k - i))
        answer /= i
    return answer

def is_valid( car_string ):
    if len(car_string) == 0:
        return True
    current_char = car_string[0]
    seen_chars = []
    for char in car_string:
        if char == current_char:
            pass
        elif char in seen_chars:
            return False
        else:
            seen_chars.append( current_char )
            current_char = char
    return True


f = open( sys.argv[1] )

num_cases = int(f.readline().split()[0])

for i in range(num_cases):
    line = f.readline().strip()
    if len(line) <= 0:
        continue
    num_cars = int(line)
    cars = f.readline().strip().split()
    if len( cars ) != num_cars:
        print "PROBLEM!"

    # First check to make sure each car is valid
    count = -1
    for car in cars:
        if not is_valid( car ):
            count = 0

    if count == 0:
        print "Case #" + str(i+1) + ":", "0"
        continue


    # Combine at those by making a new car and saying how many ways you could have done that
    count = 1
    all_letters = set(list("".join( cars )))
    for letter in all_letters:
        cars_with_letter = [car for car in cars if letter in car]
        # Get number of ways of combining this car
        # split into cars that are all one letter and cars that aren't
        single_letter = [car for car in cars_with_letter if car[0] == car[-1]]
        multi_letter = [car for car in cars_with_letter if car[0] != car[-1]]

        # First, combine all the single letter ones
        if len(single_letter) > 0 and len(multi_letter) == 0:
            #print "Going in first"
            count *= factorial(len(single_letter))
            combined_car = letter
            #print "Made new combined car", combined_car
        if len(single_letter) > 0 and len(multi_letter) > 0:
            #print "Going in second"
            # If it can't be combined, we go to 0
            if letter not in [car[0] for car in multi_letter] and letter not in [car[-1] for car in multi_letter]:
                count = 0
                break
            # (If it can be, we can just consider it absorbed and ignore the rest)
            else:
                count *= factorial(len(single_letter))
                single_letter = []
        if len(single_letter) == 0:
            #print "Going in third"
            if len(multi_letter) == 1:
                combined_car = multi_letter[0]
                #print "Made new combined car", combined_car
            if len(multi_letter) > 2:
                count = 0
                break
            if len(multi_letter) == 2:
                if multi_letter[0][0] == letter and multi_letter[1][-1] == letter:
                    combined_car = multi_letter[1] + multi_letter[0]
                    #print "Made new combined car", combined_car
                elif multi_letter[0][-1] == letter and multi_letter[1][0] == letter:
                    combined_car = multi_letter[0] + multi_letter[1]
                    #print "Made new combined car", combined_car
                else:
                    count = 0
                    break

        cars = [car for car in cars if letter not in car]
        cars.append( combined_car )
        if not is_valid( combined_car ):
            count = 0
            break
        #if i == 13:
            #print letter, cars, count

    # At this point, all the cars are independent
    count *= factorial(len(cars))
    count = count % 1000000007
    # But the count goes to 0 if this approach puts together things that can't
    final_train = "".join(cars)
    #if i == 13:
        #print final_train
    if not is_valid( final_train ):
        count = 0


    print "Case #" + str(i+1) + ":", count


# Time to verify some jamcoins! :)
import fileinput

def convert_to_bitstring(value):
    """
    Converts an integer to a base 2 bitstring.
    
    param: value, a positive value to convert to bitstring.
    """
    
    #Oh boy does this feel sketchy.
    bin_string = bin(value) #this starts with 0b...
    converted_value = int(bin_string[2:])
    
    return converted_value
    

def convert_bitstring_to_base(bitstring, base):
    """
    Converts a bitstring of 0s and 1s to a given base
    
    param: bitstring, an integer containing only 0s and 1s
    param: base, the base to which to convert, 2<=base<=10
    return: an integer that is the equivalent of bitstring in the given base
    """
    
    if base == 10:
        return bitstring
    
    index_from_right = 0
    converted_value = 0
    
    while bitstring > 0:
        bit = bitstring%10
        converted_value += bit*base**index_from_right
        bitstring -= bit
        bitstring //= 10
        index_from_right += 1
    
    return converted_value

def pathetic_nonprime_factor(value):
    """
    A pathetic nonprime has a factor that is less than 1,000,000.
    
    param: value, some positive integer
    return: a factor of the number < 1,000,000; None if none exists
    """
    
    for divisor in range(2, min(1000000, value)):
        if (value//divisor)*divisor == value:
            return divisor
    
    return None

def main():
    firstLine = True
    
    JAMCOIN_LENGTH = 32
    MAXIMUM_CASES = 500
    
    MINIMUM_JAMCOIN_BASE_2 = 2**(JAMCOIN_LENGTH-1) + 1
    MAXIMUM_JAMCOIN_BASE_2 = 2**JAMCOIN_LENGTH-1
    
    #wait what
    #MINIMUM_JAMCOIN_BASE_10 = convert_to_bitstring(MINIMUM_JAMCOIN_BASE_2)
    #MAXIMUM_JAMCOIN_BASE_10 = convert_to_bitstring(MAXIMUM_JAMCOIN_BASE_2)
    
    MAX_BASE = 10
    MIN_BASE = 2
    
    case = 1
    
    print('CASE #1:')
    # Go through all possible 16-length jamcoins.
    for jamcoin_value in range(MINIMUM_JAMCOIN_BASE_2,
                                MAXIMUM_JAMCOIN_BASE_2+1):
        if jamcoin_value%2 == 0:
            continue
        
        # Figure out if this value is a jamcoin.
        divisors = []
        bitstring = convert_to_bitstring(jamcoin_value)
        for base in range(MIN_BASE, MAX_BASE + 1):
            value_in_base = convert_bitstring_to_base(bitstring, base)
            divisor = pathetic_nonprime_factor(value_in_base)
            if divisor:
                divisors.append(divisor)
            else:
                break
        
        # If we have divisors for all 9 bases, we found a jamcoin!
        if len(divisors) == MAX_BASE - MIN_BASE + 1:
            print(bitstring, end=' ')
            for divisor in divisors:
                print(divisor, end=' ')
            print()
            case += 1
        
        # Only need 50 of these
        if case > MAXIMUM_CASES:
            break
        


if __name__ == "__main__":
    main()

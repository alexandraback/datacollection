#include "main.h"

#include <sstream>
#include <cmath>

using namespace std;

const static size_t kLinesPerTest = 1;

size_t decimalDigitsOf(size_t i) {
   int div=1, digits=0;
   while(i/div){
      digits++; div *= 10;
   }
   return digits;
}

size_t swapDecimal(size_t i) {
   if (i < 10) return i;
   int div=1, digits=0;
   while(i/div){
      digits++;div*=10;
   }
   long double result = 0;
   int tmp = digits;
   for (int x=1; x<=digits;x++) {
      result += (i%10)*pow((long double)10, (int)--tmp);
      i/=10;
   }
   return result;
}

bool solveTest(
   const vector<string>& lines,
   size_t startingIndex,
   string& result,
   size_t& linesUsed) {

   if (startingIndex + kLinesPerTest > lines.size())
      return false;
   linesUsed = kLinesPerTest;

   size_t numToReach = stoi(lines[startingIndex]);

   #if 1
   //TESTING
   assert(swapDecimal(98) == 89);
   assert(swapDecimal(5) == 5);
   assert(swapDecimal(123) == 321);
   #endif

   size_t digitsOfNumToReach = decimalDigitsOf(numToReach);
   size_t minCount = numToReach;
   size_t current = 0;
   size_t count = 0;
   size_t multToReach = numToReach / pow(10, digitsOfNumToReach - 1);

   //Don't worry about anything for one-digit nums
   if (digitsOfNumToReach == 1) {
      minCount = numToReach;
      stringstream answer;
      answer << minCount;
      result = answer.str();
      return true;
   }

   while (current < numToReach) {
      //TRACE("  " << current << " " << numToReach);
      size_t digitsOfCurrent = decimalDigitsOf(current);
      assert(digitsOfCurrent <= digitsOfNumToReach);

      //Reached the proper order of magnitude
      if (digitsOfNumToReach == digitsOfCurrent) {
         size_t currentMult = current / pow(10, digitsOfCurrent-1);
         if (currentMult == multToReach) {
            current++;
         }
         else {
            if (current % 10 == multToReach) {
               current = swapDecimal(current);
            }
            else {
               current++;
            }
         }
         count++;
      }
      //Still not in the same order of magnitude yet, run up to 9 then swap
      else {
         size_t firstDig = current / pow(10, digitsOfCurrent-1);
         size_t lastDig = current % 10;
         if (current % 10 == 9 && (firstDig != lastDig)) {
            current = swapDecimal(current);
         }
         else {
            current++;
         }
         count++;
      }
   }

   stringstream answer;
   answer << count;
   result = answer.str();

   return true;
}
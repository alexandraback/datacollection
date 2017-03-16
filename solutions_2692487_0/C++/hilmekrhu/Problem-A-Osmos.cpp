/*
 * Problem-A-Osmos.cpp
 *
 *  Created on: 04.05.2013
 *      Author: XStalkerX
 */

#include <fstream>
#include <iostream>

#include <vector>
#include <algorithm>

int get_adding (int mote, std::vector<int>& motes)
{
  int additional_moves = 1;
  motes.push_back(mote - 1);

  std::sort(motes.begin(), motes.end());

  bool eating = true;
  int current_mote = 0;

  while (eating and current_mote < motes.size())
  {
    if (mote > motes[current_mote])
      mote += motes[current_mote];
    else
      eating = false;

    ++current_mote;
  }

  if (eating)
    return additional_moves;

  if (current_mote == motes.size())
    return additional_moves + 1;

  std::vector<int> remaining_motes(motes.begin() + current_mote - 1,
                                   motes.end());

  int removing = motes.size() - current_mote + 1;
  int adding = get_adding(mote, remaining_motes);

  additional_moves += std::min (removing, adding);

  return additional_moves;
}

int solve (int mote, std::vector<int>& motes)
{
//  std::cout << "motes: ";
//  for (int a = 0; a < motes.size(); ++a)
//  {
//    std::cout << motes[a] << " ";
//  }
//  std::cout << std::endl;;

  if (mote == 1)
    return motes.size();

  std::sort(motes.begin(), motes.end());

  int growing_mote = mote;
  bool eating = true;

  int current_mote = 0;

  while (eating and current_mote < motes.size())
  {
    if (growing_mote > motes[current_mote])
      growing_mote += motes[current_mote];
    else
      eating = false;

    ++current_mote;
  }

  if (eating)
    return 0;

  if (current_mote == motes.size())
    return 1;

  std::vector<int> remaining_motes(motes.begin() + current_mote - 1,
                                   motes.end());

  int removing = motes.size() - current_mote + 1;
  int adding = get_adding(growing_mote, remaining_motes);

  return std::min(removing, adding);
}

int main (int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cout << "No file" << std::endl;
    return 0;
  }

  std::ifstream input (argv[1], std::fstream::in);
  if (!input.is_open())
  {
    std::cout << "Can't read" << std::endl;
    return -1;
  }

  std::ofstream output ("Osmos.out", std::fstream::out);
  if (!output.is_open())
  {
    std::cout << "Can't write" << std::endl;
    return -1;
  }

  /* scroll example:
    4
    2 2
    2 1
    2 4
    2 1 1 6
    10 4
    25 20 9 100
    1 4
    1 1 1 1
  */

  int cases_num = 0;
  input >> cases_num;

  int actions_needed = 0;

  int mote = 0;
  int motes_num;
  int new_mote = 0;
  std::vector<int> motes;

  // for each test case
  for (int i = 1; i <= cases_num; ++i)
  {
    input >> mote;
    input >> motes_num;
    motes.reserve(motes_num);

    // add each given mote
    for (int m = 0; m < motes_num; ++m)
    {
      input >> new_mote;
      motes.push_back(new_mote);
    }

    actions_needed = solve(mote, motes);
    output << "Case #" << i << ": " << actions_needed << std::endl;
    motes.clear();
  }

  input.close();
  output.close();
}

